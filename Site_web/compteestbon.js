let difficulte = voilaTaChance();
const petits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const grands = [25, 50, 75, 100];
let tous = [];
let objectif;
let nbrTirage;

function tirerNombres() {
  let tirage = [];
  if (difficulte <= 33){
    nbrTirage = 3;
  }
  else if (difficulte >=66){
    nbrTirage = 5;
  }
  else{
    nbrTirage = 4;
  }

  for (let i = 0; i < 2; i++) {
    let index = Math.floor(Math.random() * grands.length);
    tirage.push(grands[index]);
  }

  for (let i = 0; i < nbrTirage; i++) {
    let index = Math.floor(Math.random() * petits.length);
    tirage.push(petits[index]);
  }

  tous = [...tirage];

  objectif = Math.floor(Math.random() * 900) + 100;

  document.getElementById("nombres").innerText = `Nombres disponibles : ${tous.join(", ")}`;
  document.getElementById("objectif").innerText = objectif;
}

function verifierSolution() {
  const saisie = document.getElementById("solution").value;
  const feedback = document.getElementById("feedback");

  try {
    const resultat = eval(saisie);

    const utilisés = saisie.match(/\d+/g)?.map(Number) || [];

    const tousDispo = utilisés.every(num => tous.includes(num) && utilisés.filter(n => n === num).length <= tous.filter(n => n === num).length);

    if (!tousDispo) {
      feedback.innerText = "Vous avez utilisé un ou plusieurs nombres non autorisés.";
      return;
    }

    if (resultat === objectif) {
      feedback.innerText = "Bravo, vous avez trouvé la solution exacte !";
      setTimeout(() => {
        window.location.href = "17.html";
      }, 2000);
    } else {
      feedback.innerText = `Résultat obtenu : ${resultat}. Ce n'est pas le bon nombre.`;
    }

  } catch {
    feedback.innerText = "Formule invalide. Utilisez uniquement des chiffres et des opérateurs (+, -, *, /).";
  }
}

window.onload = tirerNombres;
