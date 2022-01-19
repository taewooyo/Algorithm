import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    val (a, b) = br.readLine().split(' ').map { it.toInt() }

    val answer = if(a>b) ">" else if(a<b) "<" else "=="

    str.append("$answer")
    println(str.toString())
    br.close()
}