import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    grouped_emails=person.groupby("email")
    duplicate_groups=grouped_emails.filter(lambda group:len(group)>1)
    h=duplicate_groups.drop_duplicates()
    res=h[["email"]]
    res=res.drop_duplicates()
    return res 
