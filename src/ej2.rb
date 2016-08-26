#include <vector>
#include <utility>
#include <iostream>





def damePesos p=0, res={d: [], i: []}, anterior="nada", valor_anterior=0, paso=0
  if p == 0
    resto = p % 3
    p = p / 3
    if paso == 0
      anterior = "sumo"
      paso = paso + 1
      res = {d: res[:d], i: res[:i].concat(3**paso)}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 2 and (anterior == "nada" || anterior == "sumo")
      anterior = "resto"
      paso = paso + 1
      res = {d: res[:d].concat(3**paso), i: res[:i]}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 2 and (anterior == "resto")
      anterior = "nada"
      paso = paso + 1
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 1 and anterior == "nada"
      anterior = "sumo"
      paso = paso + 1
      res = {d: res[:d], i: res[:i].concat(3**paso)}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 1 and anterior == "resto"
      anterior = "resto"
      paso = paso + 1
      res = {d: res[:d].concat(3**paso), i: res[:i]}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 1 and anterior == "sumo"
      anterior = "sumo"
      paso = paso + 1
      res = {d: res[:d], i: res[:i].concat(3**paso)}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 0 and anterior == "resto"
      anterior = "sumo"
      paso = paso + 1
      res = {d: res[:d], i: res[:i].concat(3**paso)}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    elseif resto == 0 and anterior == "nada" and valor_anterior == 2
      anterior = "sumo"
      paso = paso + 1
      res = {d: res[:d], i: res[:i].concat(3**paso)}
      valor_anterior = resto
      res = damePesos p, res, anterior, valor_anterior, paso

    end
  end
  res
end
