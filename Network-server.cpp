void UpdateCombat(Player& player, Enemy& enemy) {
    if (player.IsTargetLocked()) {
        player.LockOnTarget(enemy);
        if (player.AttackKeyPressed()) {
            player.PerformCombo(enemy);
        }
    }
    if (enemy.IsInRange()) {
        enemy.Attack(player);
    }
}
void UpdateBossBehavior(Boss& boss, Player& player) {
    if (boss.Health < 50 && !boss.IsEnraged()) {
        boss.Enrage();
    } else if (boss.IsPlayerInRange(player)) {
        boss.Attack(player);
    } else {
        boss.Patrol();
    }
}
void UpdateEnvironment(WeatherSystem& weather, Terrain& terrain) {
    weather.ChangeWeatherState();
    terrain.UpdatePhysics();
    if (player.InteractsWithPuzzle()) {
        ActivatePuzzle();
    }
}
void UpdateCharacterStats(Player& player) {
    if (player.GainsExperience()) {
        player.LevelUp();
        player.DistributeSkillPoints();
    }
}void UpdateGraphicsEngine(Renderer& renderer) {
    renderer.ApplyGlobalIllumination();
    renderer.UpdatePostProcessing();
    renderer.RenderParticles();
}void UpdateCharacterAnimation(Character& character) {
    character.UpdateIK();
    character.AnimateBlendTree();
    if (character.IsInCombat()) {
        character.PerformAttackAnimation();
    }
}void UpdatePhysicsEngine(PhysicsEngine& physics) {
    physics.SimulateRagdoll();
    physics.ApplyVehiclePhysics();
    physics.UpdateClothSimulation();
}
