import flask as f

def get_file_content(fileName):
  content = 0
  try:
    with open(fileName, "r") as f:
      content = f.read()
    return content
  except FileNotFoundError:
    return "The file {0} isn't found !!".format(fileName)

#########################################################

app = f.Flask(__name__)

@app.route("/test_post/", methods=["GET", "POST"])
def test_post():
  if f.request.method == "POST":
    # Needs to put an str() on the f.request.form["key"] else it returns an error !!
    return "This post : {0}<br>{1}<br>".format(str(f.request.form["post_name_for_python"]), f.request.form) # Id of the post
  else:
    return get_file_content("flaskr/test_post.html")

with app.test_request_context():
  print("==>", f.url_for("test_post"))
