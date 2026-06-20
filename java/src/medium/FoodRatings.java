package medium;

import java.util.HashMap;
import java.util.PriorityQueue;

public class FoodRatings {
    HashMap<String, PriorityQueue<Integer>> cuisinesRatings;
    HashMap<String,Integer> food2Rating;
    String[] foods;
    String[] cuisines;
    int[] ratings;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        this.cuisinesRatings = new HashMap<>();
        this.food2Rating = new HashMap<>();
        this.ratings = ratings;
        this.foods = foods;
        this.cuisines = cuisines;
        for (int i = 0; i < foods.length; i++) {
            this.food2Rating.put(foods[i],i);
            if (!cuisinesRatings.containsKey(cuisines[i])) {
                cuisinesRatings.put(cuisines[i], new PriorityQueue<>((a, b) ->{
                    int compare = Integer.compare(this.ratings[b], this.ratings[a]);
                    if(compare==0){
                        return this.foods[b].compareTo(this.foods[a]);
                    }
                    return compare;
                }
                ));
            }
            cuisinesRatings.get(cuisines[i]).add(i);
        }
    }

    public void changeRating(String food, int newRating) {
        int index=this.food2Rating.get(food);
        this.ratings[index] = newRating;
        this.cuisinesRatings.get(this.cuisines[index]).remove(index);
        this.cuisinesRatings.get(this.cuisines[index]).add(index);
    }

    public String highestRated(String cuisine) {
        Integer index = this.cuisinesRatings.get(cuisine).peek();
        return  this.foods[index];
    }
}
