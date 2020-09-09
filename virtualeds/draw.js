const canvas = document.getElementById("canvas");
const ctx = canvas.getContext('2d');
const scale = 10;
const rows = 1;
const columns = canvas.width / scale;
var leds = [];
var num_leds = 60;

(function setup() {
    document.getElementById("canvas").width = scale*num_leds;
    for (var i = 0; i < num_leds; i++){
        leds.push(new Led(i));
        leds[i].draw(i);
    }

    window.setInterval(() => {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        //manipulate LEDs
        leds.forEach(element => element.setRGB(Math.floor(Math.random() * 255), Math.floor(Math.random() * 255), Math.floor(Math.random() * 255)));
        //update LEDs
        for (var i = 0; i < num_leds; i++){
            leds[i].update(i);
        }
    }, 500);
}());