import flask as f

app = f.Flask(__name__)

@app.route("/")
def index():
  print("test")
  return f.render_template("index.html")

app.run(host="127.0.0.1", port=15000, debug=True)
