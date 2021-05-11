from django.db import models


class Cliente(models.Model):
    nome = models.CharField(max_length=100)
    endereco = models.CharField(max_length=100, blank=True, null=True)
    complemento = models.CharField(max_length=100, blank=True, null=True)
    bairro = models.CharField(max_length=50, blank=True, null=True)
    cidade = models.CharField(max_length=100, blank=True, null=True)
    cep = models.CharField(max_length=10, blank=True, null=True)
    email = models.CharField(max_length=100)
    telefone = models.CharField(max_length=30, blank=True, null=True)
    foto = models.ImageField(upload_to='fotos_clientes', blank=True, null=True)

    def __str__(self):
        return f'{self.id} - {self.nome}'

    class Meta:
        verbose_name_plural = 'Clientes'


class Veiculo(models.Model):
    fabricante = models.CharField(max_length=50, blank=True, null=True)
    modelo = models.CharField(max_length=50)
    ano = models.CharField(max_length=10)
    cor = models.CharField(max_length=30, blank=True, null=True)
    placa = models.CharField(max_length=10)
    foto = models.ImageField(upload_to='fotos_veiculos', blank=True, null=True)
    id_cliente = models.ForeignKey("Cliente", on_delete=models.CASCADE)

    def __str__(self):
        return f'{self.modelo} - {self.placa}'

    class Meta:
        verbose_name_plural = 'Veiculos'


class Parametro(models.Model):
    valor = models.DecimalField(max_digits=10, decimal_places=2)
    descricao = models.CharField(max_length=60)

    def __str__(self):
        return f'{self.valor} - {self.descricao}'

    class Meta:
        verbose_name_plural = 'Parâmetros'


class Mensalista(models.Model):
    id_veiculo = models.ForeignKey(Veiculo, on_delete=models.CASCADE)
    id_parametro = models.ForeignKey(Parametro, on_delete=models.CASCADE)
    observacoes = models.TextField(blank=True, null=True)

    def __str__(self):
        return f'{self.id_veiculo} - ({self.id_parametro})'

    class Meta:
        verbose_name_plural = 'Mensalistas'


class Rotativo(models.Model):
    data_entrada = models.DateTimeField(auto_now_add=False)
    data_saida = models.DateTimeField(auto_now_add=False, blank=True, null=True)
    id_parametro = models.ForeignKey(Parametro, on_delete=models.CASCADE)
    total = models.DecimalField(max_digits=10, decimal_places=2, blank=True, null=True)
    id_veiculo = models.ForeignKey(Veiculo, on_delete=models.CASCADE)
    pago = models.BooleanField(default=False)
    observacoes = models.TextField(blank=True, null=True)

    def __str__(self):
        return f'{self.id_veiculo} ({self.id_parametro})'

    class Meta:
        verbose_name_plural = 'Rotativos'