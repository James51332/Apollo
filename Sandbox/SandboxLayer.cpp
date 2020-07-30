#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnUpdate()
{
  Apollo::RenderCommand::ClearColor(0.2f, 0.2f, 0.2f);
  Apollo::RenderCommand::Clear();
}

void SandboxLayer::OnEvent(Apollo::Event &event)
{
}
