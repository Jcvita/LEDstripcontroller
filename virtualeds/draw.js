const canvas = document.getElementById("canvas");
const ctx = canvas.getContext('2d');
const scale = 10;
const rows = 1;
const columns = canvas.width / scale;
var leds = [];
var num_leds = 100;

(function setup() {
    document.getElementById("canvas").width = scale*num_leds;
    for (var i = 0; i < num_leds; i++){
        leds.push(new Led(i));
        leds[i].draw(i);
    }

    window.setInterval(() => {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        
        //manipulate LEDs
        if (getCookie("action") == "party"){
            leds.forEach(element => element.setRGB(Math.floor(Math.random() * 255), Math.floor(Math.random() * 255), Math.floor(Math.random() * 255)));
        } else if (getCookie("action") == "rgbsliders"){
            leds.forEach(element => element.setRGB(getCookie("r"), getCookie("g"), getCookie("b")));
        } else if (getCookie("action") == "cmdenter") {
            leds.forEach(element => element.setRGB(0, 0, 0));
        }
        
        //update LEDs
        for (var i = 0; i < num_leds; i++){
            leds[i].update(i);
        }
    }, 500);
}());

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i <ca.length; i++) {
      var c = ca[i];
      while (c.charAt(0) == ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) == 0) {
        return c.substring(name.length, c.length);
      }
    }
    return "";
  }