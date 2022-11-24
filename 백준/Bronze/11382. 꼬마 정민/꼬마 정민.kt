fun main() {
  val br = System.`in`.bufferedReader()
  val (a, b, c) = br.readLine().split(" ").map { it.toLong() }
  print(a + b + c)
}