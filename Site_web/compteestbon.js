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
//le reste a été fait en grande partie par chat gpt avec quelques modifications pour simplifier le code et correspondre à nos attentes
function calculerExpression(expr) {
  expr = expr.replace(/\s+/g, '');
  const f = new Function(`return (${expr})`);
  return f();
}

function verifierSolution() {
  const saisie = document.getElementById("solution").value;
  const feedback = document.getElementById("feedback");

  try {
    if (!/^[\d\s+\-*/().]+$/.test(saisie)) {
      throw new Error("Caractères non valides.");
    }
    const utilises = saisie.match(/\d+/g)?.map(Number) || [];

    const tousDispo = utilises.every(num =>
      tous.includes(num) &&
      utilises.filter(n => n === num).length <= tous.filter(n => n === num).length
    );

    if (!tousDispo) {
      feedback.innerText = "Vous avez utilisé un ou plusieurs nombres non autorisés.";
      return;
    }
    const resultat = calculerExpression(saisie);

    if (Math.abs(resultat - objectif) < 1e-6) {
      feedback.innerText = "Bravo, vous avez trouvé la solution !";
      setTimeout(() => {
        window.location.href = "17.html";
      }, 2000);
    } else {
      feedback.innerText = `Résultat obtenu : ${resultat}. Ce n'est pas le bon nombre.`;
    }

  } catch (e) {
    feedback.innerText = "Formule invalide. Utilisez uniquement des chiffres et des opérateurs (+, -, *, /).";
  }
}

window.onload = tirerNombres;
