#include "GameEngine/AnimationSystem.h"

using namespace GameEngine::Systems;
using namespace GameEngine::Components;

void AnimationSystem::Execute(entt::registry& scene_registry, float dt)
{
	auto animation_view = scene_registry.view<AnimationComponent, DrawableComponent>();

	for (auto render_entity : animation_view)
	{
		AnimationComponent& anim = animation_view.get<AnimationComponent>(render_entity);
		anim.m_elapsed_time += dt;
		if (anim.m_elapsed_time >= anim.m_duration)
		{
			anim.m_current_frame++;
			if (anim.m_current_frame >= anim.m_frames.size())
			{
				if (anim.m_loop)
					anim.m_current_frame = 0;
				else
					anim.m_current_frame--;
			}
			
		}
		DrawableComponent& sprite = animation_view.get<DrawableComponent>(render_entity);
		sprite.m_sprite->setTextureRect(anim.m_frames[anim.m_current_frame]);
	}
}
