void UpdateDodoBossBehavior(DodoBoss& boss, float playerDistance) {
    if (boss.IsPlayerInRange(playerDistance)) {
        boss.Attack();
    } else {
        boss.Patrol();
    }
}
