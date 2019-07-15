<template>
  <div id="calculator">
    <b-container>
      <b-row>
        <b-col>
          <h1 id="ans">{{ value || 0 }}</h1>
        </b-col>
      </b-row>
      <b-row>
        <b-col @click=clearAll() class="btn btn-warning">C</b-col>
        <b-col @click=clear() class="btn btn-info">(x)</b-col>
        <b-col @click=findPercentage() class="btn btn-info">%</b-col>
        <b-col @click="common('/')" class="btn btn-info">/</b-col>
      </b-row>
      <b-row>
        <b-col @click=addDigit(7) class="btn btn-info">7</b-col>
        <b-col @click=addDigit(8) class="btn btn-info">8</b-col>
        <b-col @click=addDigit(9) class="btn btn-info">9</b-col>
        <b-col @click="common('x')" class="btn btn-info">x</b-col>
      </b-row>
      <b-row>
        <b-col @click=addDigit(4) class="btn btn-info">4</b-col>
        <b-col @click=addDigit(5) class="btn btn-info">5</b-col>
        <b-col @click=addDigit(6) class="btn btn-info">6</b-col>
        <b-col @click="common('-')" class="btn btn-info">-</b-col>
      </b-row>
      <b-row>
        <b-col @click=addDigit(1) class="btn btn-info">1</b-col>
        <b-col @click=addDigit(2) class="btn btn-info">2</b-col>
        <b-col @click=addDigit(3) class="btn btn-info">3</b-col>
        <b-col @click="common('+')" class="btn btn-info">+</b-col>
      </b-row>
      <b-row>
        <b-col @click=addDigit(0) cols="6" class="btn btn-info">0</b-col>
        <b-col  @click=addDot() class="btn btn-info">.</b-col>
        <b-col @click=equal() class="btn btn-danger">=</b-col>
      </b-row>
    </b-container>
  </div>
</template>
<script>
  export default {
    name: "calculator",
    data () {
      return {
        value: '1022',
        operator: '',
        firstNumber: '',
        secondNumber: ''
      }
    },
    methods: {
      clearAll: function() {
        this.value = '0';
      },
      clear: function() {
        var oldStr = this.value;
        var newStr = oldStr.slice(0, oldStr.length-1);
        this.value = newStr;
      },
      addDigit: function(digit) {
        if(this.value === '0')  this.value = digit.toString();
        else  this.value = this.value + digit;
      },
      addDot: function() {
        if(this.value.indexOf(".") == -1) 
          this.value = this.value + '.';  
      },
      findPercentage: function() {
        this.value = Number(this.value)/100;
        this.value = this.value.toString();
      },
      common: function(sign) {
        if(this.value.indexOf('+') == -1 &&
          this.value.indexOf('-') == -1 &&
          this.value.indexOf('x') == -1 &&
          this.value.indexOf('/') == -1) {
          this.operator = sign;
          this.firstNumber = this.value;
          this.value = this.value + sign;
        }
      },
      equal: function() {
        var id = this.value;
        if(this.firstNumber){
          this.secondNumber = id.split(this.operator).pop();
          if(this.operator == '+')  this.value = Number(this.firstNumber) + Number(this.secondNumber);
          if(this.operator == '-')  this.value = Number(this.firstNumber) - Number(this.secondNumber);
          if(this.operator == '/')  this.value = Number(this.firstNumber) / Number(this.secondNumber);
          if(this.operator == 'x')  this.value = Number(this.firstNumber) * Number(this.secondNumber); 
        }
        this.value = this.value.toString();
        this.firstNumber = '';
        this.secondNumber = '';
      }
     }
  }
</script>
<style scoped>
#calculator {
  background: rgba(104, 198, 241, 0.616);
}
#ans {
  float:right;
}
.btn {
  margin: 0.5px;
}
</style>
