from Crypto.Cipher import AES
import os
def decrypt_file(encrypted_file_path, key):
    chunk_size = 64 * 1024
    with open(encrypted_file_path, 'rb') as encrypted_file:
        iv = encrypted_file.read(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_file_path = encrypted_file_path.replace(".encrypted", ".decrypted")
    with open(encrypted_file_path, 'rb') as input_file, open(decrypted_file_path, 'wb') as output_file:
        input_file.seek(16)
        while True:
            encrypted_chunk = input_file.read(chunk_size)
            if len(encrypted_chunk) == 0:
                break
            decrypted_chunk = cipher.decrypt(encrypted_chunk)
            output_file.write(decrypted_chunk)

def decrypt_folder(folder_path, key_path):
    with open(key_path, 'rb') as key_file:
        key = key_file.read()
    for file_name in os.listdir(folder_path):
        encrypted_file_path = os.path.join(folder_path, file_name)

        if os.path.isfile(encrypted_file_path) and encrypted_file_path.endswith(".encrypted"):
            decrypt_file(encrypted_file_path, key)

# Usage
folder_path = "/home/raz/git/cyber/Ransomeware/tryme"
key_path = "/home/raz/git/cyber/Ransomeware/encryption_key.bin"
decrypt_folder(folder_path, key_path)

