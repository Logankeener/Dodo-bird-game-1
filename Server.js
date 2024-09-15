const express = require('express');
const app = express();
const firebase = require('firebase-admin');

// Initialize Firebase
firebase.initializeApp({
  // Your Firebase configuration
});

app.post('/messages', (req, res) => {
  const message = req.body;
  // Store the message in the database
  firebase.database().ref('messages').push(message);
  res.json({ success: true });
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});// Send a message to the server-side endpoint
fetch('/messages', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json'
  },
  body: JSON.stringify(message)
})
.then(response => response.json())
.then(data => {
  if (data.success) {
    console.log('Message sent successfully');
  } else {
    console.error('Error sending message');
  }
})// ... (previous game logic)

// Add game over screen
const gameOverScreen = document.createElement('div');
gameOverScreen.textContent = 'Game Over! Score: ' + score;
gameOverScreen.style.position = 'absolute';
gameOverScreen.style.top = '50%';
gameOverScreen.style.left = '50%';
gameOverScreen.style.transform = 'translate(-50%, -50%)';
gameOverScreen.style.fontSize = '36px';
gameOverScreen.style.textAlign = 'center';
gameOverScreen.style.display = 'none';
document.body.appendChild(gameOverScreen);

function gameOver() {
    // ... (existing game over logic)

    gameOverScreen.style.display = 'block';
}

// Restart button
const restartButton = document.createElement('button');
restartButton.textContent = 'Restart';
restartButton.style.position = 'absolute';
restartButton.style.top = '60%';
restartButton.style.left = '50%';
restartButton.style.transform = 'translate(-50%, -50%)';
restartButton.style.fontSize = '24px';
restartButton.addEventListener('click', () => {
    gameOverScreen.style.display = 'none';
    // Reset game state
    bird.position.set(0, 10, 0);
    birdSpeed = 0;
    pipes.forEach(pipe => scene.remove(pipe));
    pipes.length = 0;
    score = 0;
});
document.body.appendChild(restartButton);
.catch(error => {
  console.error('Error:', error);
});
