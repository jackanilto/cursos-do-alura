var tempoIniciante = $("#tempo-digitacao").text();
var campo = $(".campo-digitacao");
var frase = $(".frase").text();

$(function() {
    atualizaTamanhoFrase();
    inicializaContadores();
    inicializaJogo();
    inicializaMarcadores();
    $("#botao-reiniciar").click(reiniciaJogo);
});

function atualizaTamanhoFrase() {
    var frase = $(".frase").text();
    var numeroPalavras = frase.split(" ").length;
    var tamanhoFrase = $("#tamanho-frase");

    tamanhoFrase.text(numeroPalavras);
}

function inicializaContadores() {
    campo.on("input", function() {
        var conteudo = campo.val();

        var qtdPalavras = conteudo.split(/\s+/).length - 1;
        $("#contador-palavras").text(qtdPalavras);

        var qtdCaracteres = conteudo.length;
        $("#contador-caracteres").text(qtdCaracteres);

    });
}

function inicializaJogo() {
    var tempoRestante = $("#tempo-digitacao").text();
    campo.one("focus", function() {
        var cronometro = setInterval(function() {
            tempoRestante--;
            $("#tempo-digitacao").text(tempoRestante);
            if (tempoRestante < 1) {
                clearInterval(cronometro);
                finalizaJogo();
            }
        }, 1000);
    });
}

function finalizaJogo() {
    campo.attr("disabled", true);
    campo.addClass("campo-desativado");
    inserePlacar();
}

function inicializaMarcadores() {
    campo.on("input", function() {
        var digitado = campo.val();
        var comparado = frase.substr(0, digitado.length);
        if (digitado == comparado) {
            campo.addClass("frase-certa");
            campo.removeClass("frase-errada");
        } else {
            campo.addClass("frase-errada")
            campo.removeClass("frase-certa");
        }


    });
}

function reiniciaJogo() {
    campo.attr("disabled", false);
    campo.val("");
    $("#contador-caracteres").text("0");
    $("#contador-palavras").text("0");
    $("#tempo-digitacao").text(tempoIniciante);
    inicializaJogo();
    campo.removeClass("campo-desativado");
    campo.removeClass("frase-certa");
    campo.removeClass("frase-errada");
}