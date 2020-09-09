function Led() {
    this.r = 0;
    this.g = 0;
    this.b = 0;

    this.row = 0
    this.col = 0

    this.draw = function() {
        ctx.fillStyle = "#FFFFFF";
        ctx.fillRect(this.row, this.col, scale, scale);
    }

    this.setRGB = function(r, g, b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    this.update = function() {
        ctx.fillStyle = "rgb(" + this.r + ", " + this.g + ", " + this.b + ")"
        ctx.fillRect(this.row, this.col, scale, scale);
    }
}