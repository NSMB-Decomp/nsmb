#include "entitymodel.hpp"

using namespace WM;


WmEntityModel::WmEntityModel() {}

WmEntityModel::~WmEntityModel() {}


bool WmEntityModel::create(u32 type) {
	return false;
}

void WmEntityModel::render(Mat4x3* mtx, Vec3_32* scale) {

}

void WmEntityModel::update() {

	model.update();

	if (type == ET_FlyingBlock) {
		shadowAnim.update();
	}

}

void WmEntityModel::init(u32 animID) {

}


bool WmEntityModel::loadResources() {
	return false;
}