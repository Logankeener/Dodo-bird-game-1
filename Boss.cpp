// Example code to add new boss
Entity boss = CreateEntity();
boss.SetModel(AssetManager::GetModel("new_boss"));
boss.SetTexture(AssetManager::GetTexture("boss_texture"));
boss.SetAnimation(AssetManager::GetAnimation("boss_attack"));
