#pragma once
#include "modelbase.hpp"
#include "../../Vec.hpp"

class Model : public ModelBase {
public:

	//C1:02019a30
	//C2:02019a5c
	Model();

	//D0:020199e8
	//D1:02019a10
	//D2:020199c8
	virtual ~Model();

	//02019948
	bool create(void* bmd, u32 modelID, u32 polygonID); //Loads the model with ID modelID from the bmd, assigns texture and model, sets the polygon ID and disables ambient/emission components. returns true if successful, false otherwise.

	//02019944
	virtual void null();

	//02019934
	void renderModel();

	//02019934
	void flush() const;

	//020198c4
	virtual void render(const Vec3_32s* scale);

	//02019864
	virtual void render(const Mat4x3& transform, const Vec3_32s* scale);

	//02019858
	virtual void render();

	//02019838
	/*
		The callback is executed when the current SBC command equals cmd.
		Timings:
		A: Before
		B: During
		C: After
	*/
	void setCommandCallback(Ns3dCmdFunc func, u8* address, u8 cmd, u32 timing); //Sets the SBC command callback with the given timing (address is eliminated and only left for backwards compatibility)

	inline void setOwner(void* ptr) {
		Ns_3dDrawableSetUserData(&drawable, ptr);
	}

	inline void* getOwner() {
		return drawable.userData;
	}

	//0201980c
	Ns3dMaterialData* getMaterialData(u32 index); //returns a pointer to the model's material data with the given index (doesn't check for index out of bounds)

	//020197fc
	Ns3dMaterialList* getMaterialCollection(); //returns a pointer to the model's material collection

	//020197e0
	i32 getMaterialIndex(const Ns3dStringData* name); //returns an index to the material given by name or -1 if no matching entry could be found

	//020197d4
	Ns3dNodeList* getNodeInfo(); //returns a pointer to the node info

	//020197bc
	i32 getNodeIndex(const Ns3dStringData* name); //returns an index to the node given by name or -1 if no matching entry could be found

	//02019740
	static bool getNodeMatrixInternal(Ns3dNodeList* nodeInfo, u32 nodeIndex, Mat4x3* mtx); //If the model's matrix is on the stack, it back-calculates the node's model matrix and stores it in mtx. returns true after operation, false if the matrix wasn't on stack.

	//0201972c
	bool getNodeMatrix(u32 nodeIndex, Mat4x3* mtx); //Calls getNodeMatrixInternal on the model's node info with index nodeIndex. The resulting matrix is stored in mtx and true is returned; on failure, false is returned.

	//020196dc
	bool getNodePosition(u32 nodeIndex, Vec3_32& position); //returns the translation component of the node matrix with index nodeIndex in position. returns true on success, false on failure.

	//0201967c
	bool restoreNodeMatrix(u32 nodeIndex); //Restores the node matrix with index nodeIndex. returns true if successful, false otherwise.


	Ns3dModelData* model;
	Ns3dTextureData* texture;

	Mat4x3 matrix;

};
size_assert(Model, 0x90);
