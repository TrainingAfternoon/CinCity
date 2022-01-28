package cf.longcomps.nwerc.nwerc11

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val times = br.readLine().toInt()

    repeat(times) {
        val (m, n) = br.readLine().split(" ").map(String::toInt)

        val books = Array(m) {
            Book(it + n,
            )
        }

        val queries = br.readLine().split(" ").map(String::toInt)

        val ft = FenwickTree(m + n)

        fun printFT() {
            println(ft.arr.joinToString(" "))
        }

        printFT()

        var nIdx = n
        for (q in queries) {
            val book = books[q - 1]

            val out = book.above + ft.sum(book.pointer)
            bw.write(out.toString())
            bw.write(" ")

            ft.update(nIdx, 1)
            printFT()
            ft.update(book.pointer, -1)

            book.pointer = --nIdx
            book.above = 0
            printFT()
        }
        bw.newLine()
        bw.flush()
    }
}

private class Book(var pointer: Int, var above: Int)

private class FenwickTree(private val size: Int) {
    val arr = LongArray(size)

    fun sum(k: Int): Long {
        var s = 0L
        var ik = k + 1
        while (ik >= 1) {
            s += arr[ik - 1]
            ik -= ik and -ik
        }
        return s
    }

    fun update(k: Int, x: Int) {
        var ik = k + 1
        while (ik <= size) {
            arr[ik - 1] += x.toLong()
            ik += ik and -ik
        }
    }
}
