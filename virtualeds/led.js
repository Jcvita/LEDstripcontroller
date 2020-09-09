function Led() {
    this.r = 0;
    this.g = 0;
    this.b = 0;

    this.row = 0
    this.col = 0

    this.draw = function(indx) {
        ctx.fillStyle = "#000000";
        ctx.fillRect(indx*scale, this.row*scale, scale, scale);
    }

    this.setRGB = function(r, g, b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    this.update = function(indx) {
        ctx.fillStyle = "rgb(" + this.r + ", " + this.g + ", " + this.b + ")"
        ctx.fillRect(indx*scale, this.row*scale, scale, scale);
    }
}