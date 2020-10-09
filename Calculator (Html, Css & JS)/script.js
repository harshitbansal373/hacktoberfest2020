const numbers = document.querySelectorAll(".number");

const inputNumber = (number) => {
  if(currentInput === "0"){
    currentInput = number;
  }
  else{
    currentInput += number;
  }
}

const operators = document.querySelectorAll(".operator");

operators.forEach((operator) => {
  operator.addEventListener("click", (event) => {
    inputOperator(event.target.value);
  });
});

const calculatorScreen = document.querySelector(".calculator-screen");

const updateScreen = (number) => {
  calculatorScreen.value = number;
}

numbers.forEach((number) => {
  number.addEventListener("click", (event) => {
    inputNumber(event.target.value);
    updateScreen(currentInput);
  });
});

const inputOperator = (operator) => {
  prevInput = currentInput;
  calculationOperator = operator;
  currentInput = "0";
  currentOperator = operator;
}

let prevInput = "0";
let calculationOperator = "0";
let currentInput  = "0";
let currentOperator = "";

const equalSign = document.querySelector(".equal-sign");

equalSign.addEventListener("click", () => {
  calculate();
  updateScreen(currentInput);
});

const calculate = () => {
  let result = 0;
  switch(calculationOperator){
    case "+":
      result = parseInt(prevInput) + parseInt(currentInput);
      break;
    case "-":
      result = parseInt(prevInput) - parseInt(currentInput);
    break;
    case "*":
      result = parseInt(prevInput) * parseInt(currentInput);
    break;
    case "/":
      result = parseInt(prevInput) / parseInt(currentInput);
    break;
    default:
      return;
  }
  currentInput = result.toString();
  calculationOperator = "";

}

const clearBtn = document.querySelector(".all-clear");

clearBtn.addEventListener("click", ()=>{
  console.log("AC button is presed");
});

const clearAll = () =>{
  prevInput = "0";
  calculationOperator = "0";
  currentInput  = "0";
}

clearBtn.addEventListener("click", ()=>{
  clearAll();
  updateScreen(currentInput)
});
