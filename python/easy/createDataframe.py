import pandas as pd
from typing import List

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    data = {"student_id": [], "age": []}
    for student in student_data:
        data["student_id"].append(student[0])
        data["age"].append(student[1])
    return pd.DataFrame(data)
