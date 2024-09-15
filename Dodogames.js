// Import Phaser
import Phaser from 'phaser';

// Create a new Phaser scene
class FlappyBirdScene extends Phaser.Scene {
  constructor() {
    super('flappyBirdScene');
  }

  preload() {
    // Load your assets here
    this.load.image('background', 'background.png');
    this.load.image('bird', 'bird.png');
    this.load.image('exit_button', 'exit_button.png');
  }

  create() {
    // Set up the game world
    this.background = this.add.tileSprite(0, 0, 480, 800, 'background');
    this.bird = this.add.sprite(160, 250, 'bird');
    this.bird.body.gravity.y = 300; // Adjust gravity as needed

    // Create exit button (adjust position as needed)
    this.exitButton = this.add.image(400, 50, 'exit_button').setInteractive();
    this.exitButton.on('pointerdown', () => this.scene.start('menuScene'));
  }

  update() {
    // Handle bird movement
    this.bird.body.setVelocityY(-150); // Jump

    // Check for collisions (adjust as needed)
    if (this.bird.y >= 800) {
      // Handle game over
    }

    // Update background
    this.background.tilePositionX -= 3;
  }
}

// Create the game configuration
const config = {
  type: Phaser.AUTO,
  width: 480,
  height: 800,
  scene: [FlappyBirdScene],
};

// Create the game
const game = new Phaser.Game(config);
