import pandas as pd

# # Load the CSV file
# csv_file_path = 'bitcoin/bitcoin.links.csv'  # Replace this with your CSV file path
# df = pd.read_csv(csv_file_path)

# # Select only the src_id and dst_id columns
# df_selected = df[['src_id', 'dst_id']]

# # Save the selected columns to a txt file in "src dst" format
# df_selected.to_csv('bitcoin.txt', sep=' ', header=False, index=False)

# print("Conversion complete! The output file is saved as 'output.txt'.")







# Open the input file and the output file
input_file_path = 'higgs.txt'  # Replace this with the path to your input file
output_file_path = 'higgs1.txt'  # The file where you want to save the result

# Read the input file and write only the first two columns to the output file
with open(input_file_path, 'r') as infile, open(output_file_path, 'w') as outfile:
    for line in infile:
        # Split the line by whitespace and select the first two elements
        a, b = line.split(',')[:2]
        # Write the selected elements in "a b" format to the output file
        outfile.write(f"{a} {b}")

print("Processing complete! The output file is saved as 'output.txt'.")
