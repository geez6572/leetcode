package medium;

import java.util.ArrayList;
import java.util.List;

/**
 * @author: XueXinYu
 * @date: 9/19/25 10:20 PM
 * @description:
 */
public class Spreadsheet {

    private List<List<Integer>> sheet;
    public Spreadsheet(int rows) {
        sheet = new ArrayList<>(rows);
        for (int i = 0; i < rows; i++) {
            ArrayList<Integer> element = new ArrayList<>(26);
            for (int j = 0; j < 26; j++) {
                element.add(0);
            }
            sheet.add(element);
        }
    }

    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1));
        sheet.get(row).set(col, value);
    }

    public void resetCell(String cell) {
        this.setCell(cell,0);
    }

    private int getByCell(String cell) {
        if(!(cell.charAt(0)>='A' && cell.charAt(0)<='Z')) {
            return Integer.parseInt(cell);
        }
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1));
        return sheet.get(row).get(col);
    }

    public int getValue(String formula) {
        String[] split = formula.substring(1).split("\\+");
        if(split.length != 2) {
            return 0;
        }
        return this.getByCell(split[0])+this.getByCell(split[1]);
    }

    public static void main(String[] args) {
        Spreadsheet spreadsheet = new Spreadsheet(3);
        spreadsheet.getValue("=O126+10272");
    }
}
