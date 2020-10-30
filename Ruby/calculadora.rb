def soma(primeiro_numero, segundo_numero)
    operacao_soma = primeiro_numero + segundo_numero
end

def subtracao(primeiro_numero, segundo_numero)
    operacao_subtracao = primeiro_numero - segundo_numero
end

def multiplicacao(primeiro_numero, segundo_numero)
    operacao_multiplicacao = primeiro_numero * segundo_numero
end

def divisao(primeiro_numero, segundo_numero)
    if segundo_numero == 0   
        "Opa! Zero como divisor"
    else
        operacao_divisao = primeiro_numero / segundo_numero
    end
end
