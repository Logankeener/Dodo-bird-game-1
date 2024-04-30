import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
BIRD_SIZE = 50
BACKGROUND_SPEED = 5

# Create window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Flappy Dodo")

# Load images
background_image = pygame.image.load("background.jpg")
background_image = pygame.transform.scale(background_image, (WIDTH, HEIGHT))

bird_image = pygame.image.load("bird.png")
bird_image = pygame.transform.scale(bird_image, (BIRD_SIZE, BIRD_SIZE))

start_button_image = pygame.image.load("start_button.png")
start_button_rect = start_button_image.get_rect(center=(WIDTH // 2, HEIGHT // 2 - 50))

exit_button_image = pygame.image.load("exit_button.png")
exit_button_rect = exit_button_image.get_rect(center=(WIDTH // 2, HEIGHT // 2 + 50))

bird_rect = bird_image.get_rect(center=(WIDTH // 4, HEIGHT // 2))
bird_velocity = 0
GRAVITY = 1

game_active = False

background_x = 0

clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if not game_active and start_button_rect.collidepoint(event.pos):
                game_active = True
            elif game_active and exit_button_rect.collidepoint(event.pos):
                pygame.quit()
                sys.exit()

    keys = pygame.key.get_pressed()
    if game_active:
        if keys[pygame.K_SPACE]:
            bird_velocity = -15

    bird_velocity += GRAVITY
    bird_rect.y += bird_velocity

    if bird_rect.bottom >= HEIGHT:
        bird_rect.bottom = HEIGHT
        bird_velocity = 0

    if game_active:
        background_x -= BACKGROUND_SPEED
        if background_x < -WIDTH:
            background_x = 0

    screen.blit(background_image, (background_x, 0))
    screen.blit(background_image, (background_x + WIDTH, 0))

    if game_active:
        screen.blit(bird_image, bird_rect.topleft)
    else:
        screen.blit(start_button_image, start_button_rect.topleft)

    screen.blit(exit_button_image, exit_button_rect.topleft)

    pygame.display.flip()
    clock.tick(30)