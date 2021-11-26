import numpy as np
from string import ascii_lowercase, ascii_uppercase, punctuation

letters_small = list(ascii_lowercase)
letters_capital = list(ascii_uppercase)
special_chars = list(punctuation)
digits = list(map(lambda x: str(x), range(10)))

def generate_password(length: int = 15, nice_password: bool = False) -> str:
    """
    Generates passwords that consist of a 
    random selection of letters (upper and
    lower case), digits and 
    special characters.

    Parameters
    ______
    length: character length of password to be generated.
    nice: Letters and numbers have a higher weightage

    Returns
    ______
    A string as the password.
    """
    
    # Random percentages for each type of character.
    ratios = np.random.dirichlet(np.ones(4))

    # Number of characters of each type.
    if nice_password:
        selection_ratios = np.argsort(ratios)
        number_of_lowercase_letters = int(ratios[selection_ratios[3]] * length)
        number_of_uppercase_letters = int(ratios[selection_ratios[1]] * length)
        number_of_special_chars = int(ratios[selection_ratios[0]] * length)
        number_of_digits = int(ratios[selection_ratios[2]] * length)
    else:
        np.random.default_rng().shuffle(ratios)
        number_of_lowercase_letters = int(ratios[0] * length)
        number_of_uppercase_letters = int(ratios[1] * length)
        number_of_special_chars = int(ratios[2] * length)
        number_of_digits = int(ratios[3] * length)


    # Select random characters of each type with given ratio.
    lowercase_letters = np.random.default_rng().choice(letters_small, number_of_lowercase_letters)
    uppercase_letters =  np.random.default_rng().choice(letters_capital, number_of_uppercase_letters)
    special_chars_chosen = np.random.default_rng().choice(special_chars, number_of_special_chars)
    nums = np.random.default_rng().choice(digits, number_of_digits)

    # Conctenate arrays to make master password array.
    password = np.concatenate((lowercase_letters, 
                               uppercase_letters, 
                               special_chars_chosen, 
                               nums), axis = 0)

    # Shuffle and reverse master password array 100 times.
    for _ in range(100):
        password = password[ ::-1]
        np.random.default_rng().shuffle(password)
    
    return "".join([str(item) for item in password.astype(str)])


if __name__ == "__main__":
    print(generate_password(15, nice_password = False))