#pragma once

#include "GameEngineExportDefine.h"

#include <entt/entt.hpp>
#include "GameEngine/GameComponents.h"

namespace GameEngine
{
	namespace Systems
	{
		class GAMEENGINE_API DynamicColliderSystem
		{
		public:
			void Execute(entt::registry& scene_registry);
		};
	}
}
