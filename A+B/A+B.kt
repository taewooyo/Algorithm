fun main() {
    val br = System.`in`.bufferedReader()
    val (a, b) = br.readLine()!!.split(" ").map{it.toInt()}
    println("${a+b}")
}