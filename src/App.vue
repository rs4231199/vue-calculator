<template>
  <div id="window">
    <div v-draggable>
      <div id="app">
      <calculator/>  
      </div>
    </div>
  </div>    
</template>

<script>
  import { Draggable } from 'draggable-vue-directive'
  import calculator from './components/Calculator';

  export default {
    directives: {
      Draggable,
    },
    components: {
      calculator,
    }
  }
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
  border: solid rgb(146, 206, 230);
  border-radius: 5px;
  height: relative;
  width: 240px;
}
#window {
  background-image: url("./assets/rain.jpg");
  height: 100%;
  background-position: center;
  background-repeat: no-repeat;
  background-size: cover;
}
body, html {
  height: 100%;
  margin: 0;
}
</style>