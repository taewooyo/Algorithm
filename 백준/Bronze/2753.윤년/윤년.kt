import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    val year = br.readLine().toString().toInt()
    val answer = if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) 1 else 0
    str.append("$answer")
    println(str.toString())
    br.close()
}