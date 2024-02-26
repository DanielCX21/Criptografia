import os, base64, random

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

class AesCrypto():
    def __init__(self, key = None, iv = None):
        if key == None:
            self.key = os.urandom(32)
        if iv == None:
            self.iv = os.urandom(16)
        else:
            self.key = key
        self.cipher = Cipher(algorithms.AES(self.key), modes.CBC(self.iv))

    def encrypt(self, message):
        message = base64.b64encode(message.encode()).decode()
        for i in range( 16 - (len(message) % 16)):
            message += " "
        encryptor = self.cipher.encryptor()
        encrypted_message = encryptor.update(message.encode("utf-8"))
        encrypted_message += encryptor.finalize()
        return encrypted_message
    
    def decrypt(self, message):
        decryptor = self.cipher.decryptor()
        decrypted_message = decryptor.update(message) + decryptor.finalize()
        decrypted_message_decoded = base64.b64decode(decrypted_message)
        return decrypted_message_decoded.decode("utf-8")
    
aes = AesCrypto()

print("Chave: ", aes.key.hex())

mensagem = "IME-sec"

print("Original: ", mensagem)

mensagem_criptografado = aes.encrypt(mensagem)
print("Criptografado: ", mensagem_criptografado.hex())

mensagem_descriptografado = aes.decrypt(mensagem_criptografado)
print("Descriptografado: ", mensagem_descriptografado)
