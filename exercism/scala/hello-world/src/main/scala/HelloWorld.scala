object HelloWorld {

  def hello(): String = {
    "Hello, World!"
  }

  def hello(str: String): String = {
    val msg = "Hello, %s!"
    msg.format(str)
  }
}
