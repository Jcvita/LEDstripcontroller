from flask import Flask, render_template, redirect, url_for, request, jsonify
import utils

app = Flask(__name__)

@app.route("/")
def site():
    return render_template('index.html')

@app.route("/solidrgb", methods=["POST"])
def static_rgb():
    #send rgb data to utils file that sends data to arduino
    if request.method == "POST":
        data = request.get_json()
        
        utils.send_static_rgb(data['red'], data['green'], data['blue'])

        return jsonify(data)
        
    # return redirect(url_for("site"))

@app.route("/partymode", methods=["POST"])
def partymode():
    if request.method == "POST":
        data = request.get_json()

        utils.party_mode(int(data['freq']))

        return jsonify(data)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5001)
