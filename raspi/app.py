from flask import Flask, render_template, redirect, url_for

app = Flask(__name__)

@app.route("/")
def site():
    return render_template('index.html')

@app.route("/solid/<red>/<green>/<blue>", methods=["POST"])
def solid_color(red, green, blue)
    try:
        red, green, blue = int(red), int(green), int(blue)
    except ValueError:
        return redirect(url_for("/"))
    #send rgb data to utils file that sends data to arduino

    return redirect(url_for("/"))

