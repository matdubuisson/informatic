import flask as f

app = f.Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
  if f.request.method == "POST":
    return f.render_template("index.html", name_with_jinja="Racteur", numbers=list(range(10)))
  else:
    return f.render_template("index.html")

app.run(host="127.0.0.1", port=15000, debug=True)
