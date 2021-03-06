/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <vector>

#include "GlobalConfigurationProvider.h"

#include "core/base/Lock.h"

namespace supercomponent {

    using namespace core::base;
    using namespace core::data::dmcp;

    GlobalConfigurationProvider::GlobalConfigurationProvider(const KeyValueConfiguration& configurations) :
        m_configuration(configurations),
        m_configurationMutex()
    {}

    GlobalConfigurationProvider::GlobalConfigurationProvider() :
        m_configuration(),
        m_configurationMutex()
    {}

    GlobalConfigurationProvider::GlobalConfigurationProvider(const GlobalConfigurationProvider& configurationProvider) :
	core::dmcp::ModuleConfigurationProvider(),
        m_configuration(configurationProvider.getGlobalConfiguration()),
        m_configurationMutex()
    {}

    GlobalConfigurationProvider& GlobalConfigurationProvider::operator=(const GlobalConfigurationProvider& configurationProvider)
    {
        m_configuration = KeyValueConfiguration(configurationProvider.getGlobalConfiguration());
        return *this;
    }

    GlobalConfigurationProvider::~GlobalConfigurationProvider() {}

    KeyValueConfiguration GlobalConfigurationProvider::getConfiguration(const ModuleDescriptor& md)
    {
        Lock l(m_configurationMutex);

        if ( (md.getName() == "Monitor") || (md.getName() == "Cockpit") ) {
            return m_configuration;
        }

        // Determine subset of configuration for this client.
        KeyValueConfiguration globalConfiguration = m_configuration.getSubsetForSection("global.");

        stringstream module;
        module << md.getName() << ".";
        KeyValueConfiguration privateConfigurationBasedOnModuleName = m_configuration.getSubsetForSection(module.str());

        KeyValueConfiguration privateConfigurationBasedOnModuleIdentifier;
        if (md.getIdentifier() != "") {
            stringstream moduleIdentifier;
            moduleIdentifier << md.getName() << ":" << md.getIdentifier() << ".";
            KeyValueConfiguration privateConfigurationBasedOnModuleIdentiferIncludingModuleIdentifier;
            privateConfigurationBasedOnModuleIdentiferIncludingModuleIdentifier = m_configuration.getSubsetForSection(moduleIdentifier.str());

            // Remove string ":" + md.getIdentifier().
            const vector<string> keys = privateConfigurationBasedOnModuleIdentiferIncludingModuleIdentifier.getListOfKeys();
            vector<string>::const_iterator it = keys.begin();
            stringstream moduleIdentifierPart;
            moduleIdentifierPart << ":" << md.getIdentifier() << ".";
            stringstream sstrPrivateConfigurationWithoutModuleIdentifier;
            while (it != keys.end()) {
                string key = (*it++);

                stringstream modifiedKey;
                modifiedKey << key.substr(0, key.find(moduleIdentifierPart.str())) << "." << key.substr(key.find(moduleIdentifierPart.str()) + moduleIdentifierPart.str().length());

                sstrPrivateConfigurationWithoutModuleIdentifier << modifiedKey.str() << "=" << privateConfigurationBasedOnModuleIdentiferIncludingModuleIdentifier.getValue<string>(key) << endl;
            }
            if (sstrPrivateConfigurationWithoutModuleIdentifier.str().length() > 0) {
                sstrPrivateConfigurationWithoutModuleIdentifier >> privateConfigurationBasedOnModuleIdentifier;
            }
        }

        // Prepare configuration.
        stringstream configurationForClient;
        configurationForClient << globalConfiguration << endl;
        configurationForClient << privateConfigurationBasedOnModuleName << endl;
        configurationForClient << privateConfigurationBasedOnModuleIdentifier << endl;

        KeyValueConfiguration clientKeyValueConfiguration;
        configurationForClient >> clientKeyValueConfiguration;

        // Set up configuration object.
        return clientKeyValueConfiguration;
    }

    KeyValueConfiguration GlobalConfigurationProvider::getGlobalConfiguration() const {
        return m_configuration;
    }
}
