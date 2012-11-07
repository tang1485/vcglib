/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#ifndef __VCG_MESH
#error "This file should not be included alone. It is automatically included by complex.h"
#endif
#ifndef __VCG_VERTEX_PLUS_COMPONENT
#define __VCG_VERTEX_PLUS_COMPONENT
namespace vcg {
namespace vertex {
/** \addtogroup VertexComponentGroup
  @{
*/
/*------------------------- Base Classes  -----------------------------------------*/

  template <class S>
  struct CurvatureDirBaseType{
          typedef Point3<S> VecType;
          typedef  S   ScalarType;
          CurvatureDirBaseType () {}
          Point3<S>max_dir,min_dir; // max and min curvature direction
          S k1,k2;// max and min curvature values
  };

/*------------------------- EMPTY CORE COMPONENTS -----------------------------------------*/

template <class TT> class EmptyCore: public TT {
public:
  typedef int FlagType;
  int &Flags() { static int dummyflags(0);  assert(0); return dummyflags; }
  int cFlags() const { assert(0); return 0; }
  static bool HasFlags()   { return false; }

  typedef vcg::Point3f CoordType;
  typedef CoordType::ScalarType      ScalarType;
  CoordType &P() { static CoordType coord(0, 0, 0); return coord; }
  CoordType cP() const { static CoordType coord(0, 0, 0);  assert(0); return coord; }
  static bool HasCoord()   { return false; }

  typedef vcg::Point3s NormalType;
  NormalType &N() { static NormalType dummy_normal(0, 0, 0);  assert(0); return dummy_normal; }
  NormalType cN() const { static NormalType dummy_normal(0, 0, 0);  assert(0); return dummy_normal; }
  static bool HasNormal()   { return false; }
  static bool HasNormalOcf()   { return false; }

  typedef float QualityType;
  QualityType &Q() { static QualityType dummyQuality(0);  assert(0); return dummyQuality; }
  const QualityType &cQ() const { static QualityType dummyQuality(0);  assert(0); return dummyQuality; }
  static bool HasQuality()   { return false; }
  static bool HasQualityOcf()   { return false; }
	static bool IsQualityEnabled(const typename TT::VertexType *)   { return false; }

  typedef vcg::Color4b ColorType;
  ColorType &C() { static ColorType dumcolor(vcg::Color4b::White); assert(0); return dumcolor; }
  const ColorType &cC() const { static ColorType dumcolor(vcg::Color4b::White);  assert(0); return dumcolor; }
  static bool HasColor()   { return false; }
  static bool HasColorOcf()   { return false; }
	static bool IsColorEnabled(const typename TT::VertexType *) { return false; }

  typedef int  MarkType;
  inline void InitIMark()    {  }
  inline int cIMark()  const { assert(0); static int tmp=-1; return tmp;}
  inline int &IMark()        { assert(0); static int tmp=-1; return tmp;}
  static bool HasMark()   { return false; }
  static bool HasMarkOcf()   { return false; }
  static bool IsMarkEnabled(const typename TT::VertexType *)   { return false; }

  typedef ScalarType RadiusType;
  RadiusType &R() { static ScalarType v = 0.0; assert(0 && "the radius component is not available"); return v; }
  RadiusType cR() const { static const ScalarType v = 0.0; assert(0 && "the radius component is not available"); return v; }
  static bool HasRadius()     { return false; }
  static bool HasRadiusOcf()     { return false; }
  static bool IsRadiusEnabled(const typename TT::VertexType *)  { return false; }

  typedef vcg::TexCoord2<float,1> TexCoordType;
  TexCoordType &T() { static TexCoordType dummy_texcoord;  assert(0); return dummy_texcoord; }
  const TexCoordType &cT() const { static TexCoordType dummy_texcoord;  assert(0); return dummy_texcoord; }
  static bool HasTexCoord()   { return false; }
	static bool IsTexCoordEnabled(const typename TT::VertexType *)  { return false; }

  typename TT::TetraPointer &VTp() { static typename TT::TetraPointer tp = 0;  assert(0); return tp; }
  typename TT::TetraPointer cVTp() const  { static typename TT::TetraPointer tp = 0;  assert(0); return tp; }
  int &VTi() { static int z = 0; return z; }
  static bool HasVTAdjacency() { return false; }

  typename TT::FacePointer &VFp() { static typename TT::FacePointer fp=0;  assert(0); return fp; }
  const typename TT::FacePointer cVFp() const { static typename TT::FacePointer fp=0;  assert(0); return fp; }
  int &VFi() {static int z=0; assert(0); return z;}
  int cVFi() const {static int z=0; assert(0); return z;}
  static bool HasVFAdjacency()   {   return false; }

  typename TT::EdgePointer &VEp() { static typename TT::EdgePointer ep=0;  assert(0); return ep; }
  const typename TT::EdgePointer cVEp() const { static typename TT::EdgePointer ep=0;  assert(0); return ep; }
  int &VEi(){static int z=0; return z;}
  static bool HasVEAdjacency()   {   return false; }

	typename TT::HEdgePointer &VHp() { static typename TT::HEdgePointer ep=0;  assert(0); return ep; }
	const typename TT::HEdgePointer cVHp() const  { static typename TT::HEdgePointer ep=0;  assert(0); return ep; }
	int &VHi(){static int z=0; return z;}
	static bool HasVHAdjacency()   {   return false; }


  typedef Point3f VecType;
	typedef Point2f CurvatureType;
	float &Kh() { static float dummy = 0.f; assert(0);return dummy;}
  float &Kg() { static float dummy = 0.f; assert(0);return dummy;}
  const float &cKh() const { static float dummy = 0.f; assert(0); return dummy;}
  const float &cKg() const { static float dummy = 0.f; assert(0); return dummy;}

	typedef CurvatureDirBaseType<float> CurvatureDirType;
  VecType &PD1(){static VecType v(0,0,0); assert(0);return v;}
  VecType &PD2(){static VecType v(0,0,0); assert(0);return v;}
  const VecType &cPD1() const {static VecType v(0,0,0); assert(0);return v;}
  const VecType &cPD2() const {static VecType v(0,0,0); assert(0);return v;}

  ScalarType &K1(){ static ScalarType v = 0.0;assert(0);return v;}
  ScalarType &K2(){ static ScalarType v = 0.0;assert(0);return v;}
  const ScalarType &cK1() const {static ScalarType v = 0.0;assert(0);return v;}
  const ScalarType &cK2()const  {static ScalarType v = 0.0;assert(0);return v;}

  static bool HasCurvature()			{ return false; }
  static bool HasCurvatureDir()			{ return false; }
  static bool HasCurvatureOcf()			{ return false; }
  static bool HasCurvatureDirOcf()			{ return false; }

  static bool IsCurvatureDirEnabled(const typename TT::VertexType *)  { return false; }
  static bool IsCurvatureEnabled(const typename TT::VertexType *)  { return false; }

  template < class LeftV>
  void ImportData(const LeftV  & /*left*/ ) {
//			TT::ImportData( left);
  }
  static void Name(std::vector<std::string> & name){TT::Name(name);}
};

/*-------------------------- COORD ----------------------------------------*/
/*! \brief \em Component: \b Geometric \b Position of the vertex

  Stored as a templated Point3.
  */
template <class A, class T> class Coord: public T {
public:
  typedef A CoordType;
  typedef typename A::ScalarType      ScalarType;
  CoordType &P() { return _coord; }
  const CoordType &P() const { return _coord; }
  const CoordType &cP() const { return _coord; }

	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasCoord()) P().Import(left.cP()); T::ImportData( left); }
  static bool HasCoord()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("Coord"));T::Name(name);}

private:
  CoordType _coord;
};
template <class T> class Coord3f: public Coord<vcg::Point3f, T> {
public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("Coord3f"));T::Name(name);}
};
template <class T> class Coord3d: public Coord<vcg::Point3d, T> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Coord3d"));T::Name(name);}
};

/*-------------------------- NORMAL ----------------------------------------*/
  /*! \brief \em Component: \b %Normal of the vertex

    Stored as a templated Point3. The type of the normal can be different type  with respect to the Coord component
    */

template <class A, class T> class Normal: public T {
public:
  typedef A NormalType;
  NormalType &N() { return _norm; }
  const NormalType &cN() const { return _norm; }
	template < class LeftV>
	void ImportData(const LeftV  & left ){
		if(LeftV::HasNormal())
			N().Import(left.cN());
		T::ImportData( left);
	}
  static bool HasNormal()   { return true; }
//  static bool HasNormalOcf() { return false; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("Normal"));T::Name(name);}

private:
  NormalType _norm;
};

template <class T> class Normal3s: public Normal<vcg::Point3s, T> {
public:static void Name(std::vector<std::string> & name){name.push_back(std::string("Normal3s"));T::Name(name);}
};
template <class T> class Normal3f: public Normal<vcg::Point3f, T> {
public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("Normal3f"));T::Name(name);}
};
template <class T> class Normal3d: public Normal<vcg::Point3d, T> {
public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("Normal3d"));T::Name(name);}
};


/*-------------------------- INCREMENTAL MARK  ----------------------------------------*/
  /*! \brief Per vertex \b Incremental \b Mark

      It is just an int that allows to efficently un-mark the whole mesh. \sa UnmarkAll
      */

template <class T> class Mark: public T {
public:
  static bool HasMark()      { return true; }
  static bool HasMarkOcc()   { return true; }
  inline void InitIMark()    { _imark = 0; }
  inline const int & cIMark() const { return _imark;}
  inline int & IMark()       { return _imark;}
  inline const int & IMark() const {return _imark;}
	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasMark())  IMark() = left.IMark(); T::ImportData( left); }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("Mark"));T::Name(name);}

 private:
	int _imark;
};

/*-------------------------- TEXCOORD ----------------------------------------*/
  /*! \brief \em Component: Per vertex \b Texture Coords

      Note that to have multiple different TexCoord for a single vertex (as it happens on atlas where a vertex can belong to two triangles mapped on different portionof the texture) you have two options:
      - duplicate vertexes
      - use PerWedge Texture coords
      */

template <class A, class TT> class TexCoord: public TT {
public:
  typedef A TexCoordType;
  TexCoordType &T() { return _t; }
  const TexCoordType &cT()  const { return _t; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasTexCoord())  T() = left.cT(); TT::ImportData( left); }
  static bool HasTexCoord()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("TexCoord"));TT::Name(name);}

private:
  TexCoordType _t;
};

template <class TT> class TexCoord2s: public TexCoord<TexCoord2<short,1>, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("TexCoord2s"));TT::Name(name);}
};
template <class TT> class TexCoord2f: public TexCoord<TexCoord2<float,1>, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("TexCoord2f"));TT::Name(name);}
};
template <class TT> class TexCoord2d: public TexCoord<TexCoord2<double,1>, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("TexCoord2d"));TT::Name(name);}
};

/*------------------------- FLAGS -----------------------------------------*/
  /*! \brief \em Component: Per vertex \b Flags

      This component stores a 32 bit array of bit flags. These bit flags are used for keeping track of selection, deletion, visiting etc. \sa \ref flags for more details on common uses of flags.
      */

template <class T> class BitFlags:  public T {
public:
	BitFlags(){_flags=0;}
  typedef int FlagType;
  int &Flags() {return _flags; }
  int cFlags() const {return _flags; }
    template < class LeftV>
    void ImportData(const LeftV  & left ) { if(LeftV::HasFlags()) Flags() = left.cFlags(); T::ImportData( left); }
  static bool HasFlags()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("BitFlags"));T::Name(name);}

private:
  int  _flags;
};


/*-------------------------- Color  ----------------------------------*/
  /*! \brief \em Component: Per vertex \b Color
   *
   * Usually most of the library expects a color stored as 4 unsigned chars (so the component you use is a \c vertex::Color4b)
   * but you can also use float for the color components.
   */
template <class A, class T> class Color: public T {
public:
  Color():_color(vcg::Color4b::White) {}
  typedef A ColorType;
  ColorType &C() { return _color; }
  const ColorType &C() const { return _color; }
  const ColorType &cC() const { return _color; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasColor()) C() = left.cC();  T::ImportData( left); }
  static bool HasColor()   { return true; }
	static bool IsColorEnabled(typename T::VertexType *)   { return true; }
  static void Name(std::vector<std::string> & name){name.push_back(std::string("Color"));T::Name(name);}

private:
  ColorType _color;
};

template <class TT> class Color4b: public Color<vcg::Color4b, TT> {
	public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Color4b"));TT::Name(name);}
};

/*-------------------------- Quality  ----------------------------------*/
  /*! \brief \em Component: Per vertex \b quality
The Quality Component is a generic place for storing a float. The term 'quality' is a bit misleading and it is due to its original storic meaning. You should intend it as a general purpose container.
\sa vcg::tri::UpdateColor for methods transforming quality into colors
\sa vcg::tri::UpdateQuality for methods to manage it

*/

template <class A, class TT> class Quality: public TT {
public:
  typedef A QualityType;
  QualityType &Q() { return _quality; }
  const QualityType & cQ() const {return _quality; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasQuality()) Q() = left.cQ(); TT::ImportData( left); }
  static bool HasQuality()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("Quality"));TT::Name(name);}

private:
  QualityType _quality;
};

template <class TT> class Qualitys: public Quality<short, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Qualitys"));TT::Name(name);}
};
template <class TT> class Qualityf: public Quality<float, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Qualityf"));TT::Name(name);}
};
template <class TT> class Qualityd: public Quality<double, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Qualityd"));TT::Name(name);}
};

  /*-------------------------- Curvature   ----------------------------------*/

  /*! \brief \em Component: Per vertex basic \b curvature
    This component keeps the mean an gaussian curvature for a vertex. Used by some of the algorithms of vcg::tri::UpdateCurvature to store the computed curvatures.
      */
  template <class A, class TT> class Curvature: public TT {
  public:
          typedef Point2<A> CurvatureType;
          typedef typename CurvatureType::ScalarType ScalarType;
          ScalarType  &Kh(){ return _hk[0];}
          ScalarType  &Kg(){ return _hk[1];}
          const ScalarType &cKh() const { return  _hk[0];}
          const ScalarType &cKg() const { return  _hk[1];}

          static bool HasCurvature()   { return true; }
          static bool IsCurvatureEnabled(typename TT::VertexType *)   { return true; }
          static void Name(std::vector<std::string> & name){name.push_back(std::string("Curvature"));TT::Name(name);}

  private:
          Point2<A> _hk;
  };


  template <class T> class Curvaturef: public Curvature< float, T> {
  public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("Curvaturef"));T::Name(name);}
  };
  template <class T> class Curvatured: public Curvature<double , T> {
  public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("Curvatured"));T::Name(name);}
  };

/*-------------------------- Curvature Direction ----------------------------------*/


template <class TT> class EmptyCurvatureDir: public TT {
public:
  typedef CurvatureDirBaseType<float> CurvatureDirType;

	Point3f &PD1(){static Point3f dummy(0,0,0); return dummy;}
	Point3f &PD2(){static Point3f dummy(0,0,0); return dummy;}
	const Point3f &cPD1() const {static Point3f dummy(0,0,0); return dummy;}
	const Point3f &cPD2()const {static Point3f dummy(0,0,0); return dummy;}

	float &K1(){ static float dummy(0);assert(0);return dummy;}
	float &K2(){ static float dummy(0);assert(0);return dummy;}
	const float &cK1()const { static float dummy(0);assert(0);return dummy;}
	const float &cK2()const { static float dummy(0);assert(0);return dummy;}

  static bool HasCurvatureDir()   { return false; }
	template < class LeftV>
		void ImportData(const LeftV  & left ) { TT::ImportData( left); }
	static void Name(std::vector<std::string> & name){TT::Name(name);}
};

  /*! \brief \em Component: Per vertex \b curvature \b directions
    This component keep the principal curvature directions. Used by some of the algorithms of vcg::tri::UpdateCurvature to store the computed curvatures.
      */

template <class A, class TT> class CurvatureDir: public TT {
public:
  typedef A CurvatureDirType;
	typedef typename CurvatureDirType::VecType VecType;
	typedef typename CurvatureDirType::ScalarType ScalarType;

	VecType &PD1(){ return _curv.max_dir;}
	VecType &PD2(){ return _curv.min_dir;}
	const VecType &cPD1() const {return _curv.max_dir;}
	const VecType &cPD2() const {return _curv.min_dir;}

	ScalarType &K1(){ return _curv.k1;}
	ScalarType &K2(){ return _curv.k2;}
	const ScalarType &cK1() const {return _curv.k1;}
	const ScalarType &cK2()const  {return _curv.k2;}
	template < class LeftV>
	void ImportData(const LeftV  & left ) {
	  if(LeftV::HasCurvatureDir()) {
		PD1() = left.cPD1(); PD2() = left.cPD2();
		K1()  = left.cK1();  K2()  = left.cK2();
	  }
	  TT::ImportData( left);
	}

	static bool HasCurvatureDir()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("CurvatureDir"));TT::Name(name);}

private:
  CurvatureDirType _curv;
};


template <class T> class CurvatureDirf: public CurvatureDir<CurvatureDirBaseType<float>, T> {
public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("CurvatureDirf"));T::Name(name);}
};
template <class T> class CurvatureDird: public CurvatureDir<CurvatureDirBaseType<double>, T> {
public:	static void Name(std::vector<std::string> & name){name.push_back(std::string("CurvatureDird"));T::Name(name);}
};

/*-------------------------- Radius  ----------------------------------*/
  /*! \brief \em Component: Per vertex \b radius

    This component keep a floating point value meant to be the average distance from the surrounding vertices. Used in point clouds by some of the point splatting and MLS surface algorithms.
      */
template <class A, class TT> class Radius: public TT {
public:
  typedef A RadiusType;
  RadiusType &R() { return _radius; }
  const RadiusType & cR() const {return _radius; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) { if(LeftV::HasRadius()) R() = left.cR(); TT::ImportData( left); }
  static bool HasRadius()   { return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("Radius"));TT::Name(name);}

private:
  RadiusType _radius;
};

template <class TT> class Radiusf: public Radius<float, TT> {
public: static void Name(std::vector<std::string> & name){name.push_back(std::string("Radiusf"));TT::Name(name);}
};


/*----------------------------- VEADJ ------------------------------*/
/*! \brief \em Component: Per vertex \b Vertex-Edge adjacency relation
    It stores a pointer to the first Edge of a list edges that is stored in a distributed way on the edges themselves.

\sa vcg::tri::UpdateTopology for functions that compute this relation
\sa iterators
*/

template <class T> class VEAdj: public T {
public:
  VEAdj(){_ep=0;_zp=-1;}
  typename T::EdgePointer &VEp() {return _ep; }
  typename T::EdgePointer const cVEp() const {return _ep; }
  int &VEi() {return _zp; }
  template < class LeftV>
  void ImportData(const LeftV  & left ) {  T::ImportData( left); }
  static bool HasVEAdjacency()   {   return true; }
  static bool HasVEAdjacencyOcc()   {   return true; }
  static void Name(std::vector<std::string> & name){name.push_back(std::string("VEAdj"));T::Name(name);}

private:
  typename T::EdgePointer _ep ;
  int _zp ;
};

/*----------------------------- VFADJ ------------------------------*/
  /*! \brief \em Component: Per vertex \b Vertex-Face adjacency relation

It stores a pointer to the first Face of a list of Faces that is stored in a distributed way on the faces themselves.
Note that if you use this component it is expected that on the Face you use also the corresponding vcg::face::VFAdj component.

  \sa vcg::tri::UpdateTopology for functions that compute this relation
  \sa iterators
  */

template <class T> class VFAdj: public T {
public:
  VFAdj(){_fp=0;_zp=-1;}
  typename T::FacePointer &VFp() {return _fp; }
	typename T::FacePointer const cVFp() const  {return _fp; }
  int &VFi() {return _zp; }
  int const &cVFi() const {return _zp; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) { T::ImportData( left); }
  static bool HasVFAdjacency()   {   return true; }
  static bool HasVFAdjacencyOcc()   {   return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("VFAdj"));T::Name(name);}

private:
  typename T::FacePointer _fp ;
  int _zp ;
};

/*----------------------------- VHADJ ------------------------------*/

template <class T> class VHAdj: public T {
public:
	VHAdj(){_hp=0;_zp=-1;}
	typename T::HEdgePointer &VHp() {return _hp; }
	typename T::HEdgePointer cVHp() {return _hp; }
	int &VHi() {return _zp; }
	template < class LeftV>
	void ImportData(const LeftV  & left ) {  T::ImportData( left); }
	static bool HasVHAdjacency()   {   return true; }
	static bool HasVHAdjacencyOcc()   {   return true; }
	static void Name(std::vector<std::string> & name){name.push_back(std::string("VHAdj"));T::Name(name);}

private:
	typename T::HEdgePointer _hp ;
	int _zp ;
};

/*----------------------------- VTADJ ------------------------------*/

template <class T> class VTAdj: public T {
public:
	VTAdj() { _tp = 0; _zp=-1;}
	typename T::TetraPointer &VTp() { return _tp; }
	typename T::TetraPointer cVTp() { return _tp; }
	int &VTi() {return _zp; }
	static bool HasVTAdjacency() { return true; }
	static bool HasVTAdjacencyOcc()   {   return true; }
	static void Name( std::vector< std::string > & name ) { name.push_back( std::string("VTAdj") ); T::Name(name); }

private:
	typename T::TetraPointer _tp ;
	int _zp ;
};

  /** @} */   // End Doxygen VertexComponentGroup
  } // end namespace vert
}// end namespace vcg
#endif
