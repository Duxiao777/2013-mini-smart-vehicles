/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_THREED_MODELS_TRIANGLE_H_
#define HESPERIA_CORE_THREED_MODELS_TRIANGLE_H_

#include <vector>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "hesperia/data/environment/Point3.h"
#include "hesperia/threeD/Node.h"
#include "hesperia/threeD/NodeDescriptor.h"

namespace hesperia {
    namespace threeD {
        namespace models {

            using namespace std;

            /**
             * This class represents a triangle.
             */
            class HESPERIA_API Triangle : public Node {
                public:
                    Triangle();

                    /**
                     * Constructor.
                     *
                     * @param nodeDesciptor Description for this node.
                     */
                    Triangle(const NodeDescriptor &nodeDescriptor);

                    /**
                     * Copy constructor.
                     *
                     * @param obj Reference to an object of this class.
                     */
                    Triangle(const Triangle &obj);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Reference to an object of this class.
                     * @return Reference to this instance.
                     */
                    Triangle& operator=(const Triangle &obj);

                    virtual ~Triangle();

                    virtual void render(const RenderingConfiguration &renderingConfiguration) const;

                    /**
                     * This method sets the triangle's vertices.
                     *
                     * @param a Vertex a.
                     * @param b Vertex b.
                     * @param c Vertex c.
                     */
                    void setVertices(const data::environment::Point3 &a, const data::environment::Point3 &b, const data::environment::Point3 &c);

                    /**
                     * This method returns the triangle's vertices.
                     *
                     * @return Triangle's vertices.
                     */
                    vector<data::environment::Point3> getVertices() const;

                    /**
                     * This method sets the triangle's normal.
                     *
                     * @param n Normal.
                     */
                    void setNormal(const data::environment::Point3 &n);

                    /**
                     * This method returns the triangle's normal.
                     *
                     * @return Triangle's normal.
                     */
                    data::environment::Point3 getNormal() const;

                    /**
                                    * This method sets the triangle's texture coordinates.
                                    *
                                    * @param ta Texture coordinate for vertex a.
                                    * @param tc Texture coordinate for vertex b.
                                    * @param tb Texture coordinate for vertex c.
                                    */
                    void setTextureCoordinates(const data::environment::Point3 &ta, const data::environment::Point3 &tb, const data::environment::Point3 &tc);

                    /**
                     * This method returns the triangle's texture coordinates.
                     *
                     * @return Triangle's texture coordinates.
                     */
                    vector<data::environment::Point3> getTextureCoordinates() const;

                private:
                    vector<data::environment::Point3> m_vertices;
                    data::environment::Point3 m_normal;
                    vector<data::environment::Point3> m_textureCoordinates;
            };

        }
    }
} // hesperia::threeD::models

#endif /*HESPERIA_CORE_THREED_MODELS_TRIANGLE_H_*/
