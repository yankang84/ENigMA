// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// *****************************************************************************

#pragma once

#include <map>
#include <vector>

#include "GeoVolume.hpp"
#include "GeoPolygon.hpp"

#include "GeoTetrahedron.hpp"
#include "GeoTriangularPrism.hpp"
#include "GeoHexahedron.hpp"

namespace ENigMA
{

    namespace geometry
    {

        // Represents a convex polyhedron.

        template <typename Real>
        class CGeoPolyhedron : public CGeoVolume<Real>
        {
        protected:

            typedef std::map<Integer, CGeoPolygon<Real> > mapPolygon;
            mapPolygon m_polygons;

            std::vector<Integer> m_polygonIds;

        public:

            CGeoPolyhedron();
            CGeoPolyhedron(CGeoTetrahedron<Real>& aTetrahedron);
            CGeoPolyhedron(CGeoTriangularPrism<Real>& aTriangularPrism);
            CGeoPolyhedron(CGeoHexahedron<Real>& aHexahedron);

            ~CGeoPolyhedron();

            void reset();

            Integer polygonId(const Integer aPolygonIndex);
            CGeoPolygon<Real>& polygon(const Integer aPolygonId);
            void addPolygon(const Integer aPolygonId, CGeoPolygon<Real>& aPolygon);
            Integer nbPolygons();

            bool containsPolygon(const Integer aPolygonId);

            void triangulate();

            void close(CGeoPolygon<Real>& aNewPolygon, const Integer aNewPolygonId, CGeoNormal<Real>& aNormal, Real const aTolerance = 0);

            inline void calculateCentroid(bool bReCalculate = false);
            inline void calculateSurfaceArea(bool bReCalculate = false);
            inline void calculateVolume(bool bReCalculate = false);
            inline void calculateBoundingBox(bool bReCalculate = false);

            void set(CGeoPolyhedron<Real>& aPolyhedron);

            inline CGeoPolyhedron<Real> clip(CGeoPolygon<Real>& aNewPolygon, const Integer aNewPolygonId, CGeoPlane<Real>& aPlane, const Real aTolerance = 0);
            inline CGeoPolyhedron<Real> clip(CGeoPolygon<Real>& aNewPolygon, const Integer aNewPolygonId, CGeoNormal<Real>& aNormal, Real& d, Real volumeFractionReq, Real& volumeFractionAct, Integer& nIterations, const Integer nMaxIterations = 50, const Real aTolerance = 0);

            inline CGeoPolyhedron<Real> cut(CGeoPolyhedron<Real>& aNewPolyhedron, CGeoPolygon<Real>& aNewPolygon, const Integer aNewPolygonId, CGeoPlane<Real>& aPlane, const Real aTolerance = 0);
            inline CGeoPolyhedron<Real> cut(CGeoPolyhedron<Real>& aNewPolyhedron, CGeoPolygon<Real>& aNewPolygon, const Integer aNewPolygonId, CGeoNormal<Real>& aNormal, Real& d, Real volumeFractionReq, Real& volumeFractionAct, Integer& nIterations, const Integer nMaxIterations = 50, const Real aTolerance = 0);

        };

    }

}

#include "GeoPolyhedron_Imp.hpp"
