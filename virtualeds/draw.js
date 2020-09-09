const canvas = document.querySelector(".canvas");
const ctx = canvas.getContext("2d");
const scale = 10;
const rows = 1;
const columns = canvas.width / scale;
var leds = [];
var num_leds = 10;


function setup() {
    for (var i = 0; i < num_leds; i++){
        leds.push(new Led());
    }
    leds.forEach(element => element.draw())

    window.setInterval(() => {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        leds.forEach(element => element.update())
    })
}