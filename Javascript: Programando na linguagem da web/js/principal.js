var titulo = document.querySelector(".titulo");
titulo.textContent = "Aparecida Nutricionista";

var paciente = document.querySelector("#primeiro-paciente");

var tdPeso = paciente.querySelector(".info-peso");
var peso = tdPeso.textContent;

var tdAltura = document.querySelector(".info-altura");
var altura = tdAltura.textContent;

if (peso < 0 || peso > 1000) {
    console.log("Peso Inválido");
}

if (altura < 0 || altura > 3.00) {
    console.log("Altura Inválida");
}
var imc = peso / (altura * altura);

var tdImc = document.querySelector(".info-imc");
tdImc.textContent = imc;

console.log(imc)