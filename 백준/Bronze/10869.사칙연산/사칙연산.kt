import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    var token : StringTokenizer? = null
    token = StringTokenizer(br.readLine())

    val a = token.nextToken().toInt()
    val b = token.nextToken().toInt()
    println(a + b)
    println(a - b)
    println(a * b)
    println(a / b)
    println(a % b)
    br.close()
}
