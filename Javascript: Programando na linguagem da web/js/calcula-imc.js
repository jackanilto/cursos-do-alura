var titulo = document.querySelector(".titulo");
titulo.textContent = "Aparecida Nutricionista";

var pacientes = document.querySelectorAll(".paciente");

for (var i = 0; i < pacientes.length; i++) {
    var paciente = pacientes[i];

    var tdPeso = paciente.querySelector(".info-peso");
    var peso = tdPeso.textContent;

    var tdAltura = paciente.querySelector(".info-altura");
    var altura = tdAltura.textContent;

    var tdImc = paciente.querySelector(".info-imc");

    var pesoEhValido = validaPeso(peso);
    var alturaEhValida = validaAltura(altura);

    if (!pesoEhValido) {
        console.log("Peso Inválido");
        tdImc.textContent = "Peso Inválido";
        paciente.classList.add("paciente-invalido");
    }

    if (!validaAltura) {
        console.log("Altura Inválida");
        tdImc.textContent = "Altura Inválido";
        paciente.classList.add("paciente-invalido");
    }

    if (pesoEhValido && alturaEhValida) {
        var imc = calculaImc(peso, altura);
        tdImc.textContent = imc;
    }
}

function calculaImc(peso, altura) {
    var imc = 0;
    imc = peso / (altura * altura);
    return imc.toFixed(2);
}

function validaPeso(peso) {
    if (peso <= 0 || peso >= 1000) {
        return false;
    } else {
        return true;
    }
}

function validaAltura(altura) {
    if (altura <= 0 || altura >= 3.00) {
        return false;
    } else {
        return true;
    }
}