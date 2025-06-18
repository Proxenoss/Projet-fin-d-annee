let difficulte = voilaTaChance();
let curseur = document.getElementById("curseur");
let btn = document.getElementById("attackBtn");
let message = document.getElementById("message");
let levelDisplay = document.getElementById("level");
console.log(difficulte)
let vitesse = 2;
let level = 1;
let position = 0;
let direction = 1;
let interval;
let maxLevel;

if (difficulte <=24){
    maxLevel = 10;
}
else if (difficulte <=49){
    maxLevel = 8;
}
else if (difficulte <= 74){
    maxLevel = 6;
}
else {
    maxLevel = 4;
}

function moveCursor() {
  position += vitesse * direction;
  if (position > 290 || position < 0) {
    direction *= -1;
  }
  curseur.style.left = position + "px";
}

function startGame() {
  interval = setInterval(moveCursor, 10);
}

btn.addEventListener("click", () => {
  clearInterval(interval);
  const successZoneStart = 120;
  const successZoneEnd = 180;

  if (position >= successZoneStart && position <= successZoneEnd) {
    if (level === maxLevel) {
      message.textContent = "Victoire !";
      setTimeout(() => window.location.href = "26.html", 1000);
    } else {
      level++;
      vitesse += 0.6;
      levelDisplay.textContent = level;
      message.textContent = "Attaque réussie ! Prépare-toi pour le prochain duel...";
      position = 0;
      setTimeout(() => {
        message.textContent = "";
        startGame();
      }, 1500);
    }
  } else {
    message.textContent = "Attaque ratée... tu as été vaincu.";
    setTimeout(() => location.reload(), 1000);
  }
});

startGame();
