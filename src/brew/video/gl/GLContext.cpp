/**
 *
 *  |_  _ _
 *  |_)| (/_VV
 *
 *  Copyright 2015-2017 random arts
 *
 *  Created on: 06.09.17
 *
 */

#include <brew/video/gl/GLContext.h>
#include <brew/video/gl/GLFrameBuffer.h>
#include <brew/video/gl/GLTexture.h>
#include <brew/video/gl/GLShaderVariables.h>
#include <brew/video/gl/GLExtensions.h>
#include <brew/video/gl/GLVertexBuffer.h>

namespace brew {

GLContext::GLContext() {
    GLExtensions::init();
}

std::unique_ptr<FrameBufferContextHandle> GLContext::createObject(FrameBuffer& frameBuffer) {
    return std::make_unique<GLFrameBufferContextHandle>(*this, frameBuffer);
}

std::unique_ptr<TextureContextHandle> GLContext::createObject(Texture& texture) {
    return std::make_unique<GLTextureContextHandle>(*this, texture);
}

std::unique_ptr<ShaderVariablesContextHandle> GLContext::createObject(ShaderVariables& shaderVariables) {
    return std::make_unique<GLShaderVariablesContextHandle>(*this, shaderVariables);
}

void GLContext::updateObject(ShaderVariables& shaderVariables) {
    auto& handle = static_cast<GLShaderVariablesContextHandle&>(*shaderVariables);
    handle.syncToGPU(shaderVariables, false);
}

std::unique_ptr<VertexBufferContextHandle> GLContext::createObject(VertexBuffer& vertexBuffer) {
    return std::make_unique<GLVertexBufferContextHandle>(*this, vertexBuffer);
}

void GLContext::updateObject(VertexBuffer& vertexBuffer) {
    auto& handle = static_cast<GLVertexBufferContextHandle&>(*vertexBuffer);
    handle.sync(vertexBuffer);
}

} /* namespace brew */
