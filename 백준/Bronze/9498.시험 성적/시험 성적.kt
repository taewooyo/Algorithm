import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    val score = br.readLine().toString().toInt()
    val grade : String = when (score) {
        in 90..100 -> "A"
        in 80..89 -> "B"
        in 70..79 -> "C"
        in 60..69 -> "D"
        else -> "F"
    }
    str.append(grade)
    println(str.toString())
    br.close()
}