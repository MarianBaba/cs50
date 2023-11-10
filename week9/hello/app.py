from flask import *

app = Flask(__name__)

@app.route("/")
def index():
    # datatype of request.args = dictionary
    # name = request.args.get("name", "world")
    return render_template("index.html")


@app.route("/greet")
def greet():
    return render_template("greet.html", name=request.args.get("name", "world"))