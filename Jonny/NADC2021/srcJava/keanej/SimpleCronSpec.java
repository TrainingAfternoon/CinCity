package keanej;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class SimpleCronSpec {
	public static void main(String[] args) {
		byte[][][] data = new byte[24][60][60];
		int n;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		
		for (int i = 0; i < n; ++i) {
			String[] hrs = in.next().split(",");
			String[] mins = in.next().split(",");
			String[] secs = in.next().split(",");
			List<Integer> hrsInts = new ArrayList<>(24);
			List<Integer> minsInts = new ArrayList<>(60);
			List<Integer> secsInts = new ArrayList<>();
			if (hrs[0].equals("*")) {
				hrsInts = IntStream.rangeClosed(0,  23).boxed().collect(Collectors.toList());
			} else {
				for (String hr: hrs) {
					String[] hrRanges = hr.split("-");
					if (hrRanges.length == 1) {
						hrsInts.add(Integer.parseInt(hrRanges[0]));
					} else {
						for (int j = Integer.parseInt(hrRanges[0]); j <= Integer.parseInt(hrRanges[1]); ++j) {
							hrsInts.add(j);
						}
					}
				}
			}
			if (mins[0].equals("*")) {
				minsInts = IntStream.rangeClosed(0,  59).boxed().collect(Collectors.toList());
			} else {
				for (String min: mins) {
					String[] minRanges = min.split("-");
					if (minRanges.length == 1) {
						minsInts.add(Integer.parseInt(minRanges[0]));
					} else {
						for (int j = Integer.parseInt(minRanges[0]); j <= Integer.parseInt(minRanges[1]); ++j) {
							minsInts.add(j);
						}
					}
				}
			}
			if (secs[0].equals("*")) {
				secsInts = IntStream.rangeClosed(0,  59).boxed().collect(Collectors.toList());
			} else {
				for (String sec: secs) {
					String[] secRanges = sec.split("-");
					if (secRanges.length == 1) {
						secsInts.add(Integer.parseInt(secRanges[0]));
					} else {
						for (int j = Integer.parseInt(secRanges[0]); j <= Integer.parseInt(secRanges[1]); ++j) {
							secsInts.add(j);
						}
					}
				}
			}
			for (int hour: hrsInts) {
				for (int min: minsInts) {
					for (int sec: secsInts) {
						++data[hour][min][sec];
					}
				}
			}		
		}
		long totalJobs = 0;
		long totalJobStartsSecs = 0;
		for (byte[][] hour: data) {
			for (byte[] min: hour) {
				for (byte sec: min) {
					if (sec != 0) {
						++totalJobStartsSecs;
						totalJobs += sec;
					}
				}
			}
		}
		System.out.println(totalJobStartsSecs +  " " + totalJobs);
		in.close();
	}
}
