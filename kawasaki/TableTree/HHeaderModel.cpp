#include <QSize>

#include "HHeaderModel.h"

HHeaderModel::HHeaderModel(QObject *parent)
{
    _MaxCol = 0;
}
HHeaderModel::~HHeaderModel()
{
}

void HHeaderModel::setItem(int row, int col, const QString& text)
{
    ModelData* data = new ModelData();
    data->_text = text;
   
    _modelData[row][col] = data;

    if (_MaxCol < col)
    {
        _MaxCol = col;
    }
}

QString HHeaderModel::item(int row, int col)
{
    QMap<int, QMap<int, ModelData*> >::Iterator iterRow = _modelData.find(row);
    if (iterRow == _modelData.end() || iterRow.value().isEmpty())
        return QString();

    QMap<int, ModelData*>::Iterator iterCol = iterRow.value().find(col);
    if (iterCol == iterRow.value().end())
    {
        return QString();
    }

    return iterCol.value()->_text;
}

void HHeaderModel::setSpan(int firstRow, int firstColumn, int rowSpanCount, int columnSpanCount)
{
    for(int row = firstRow; row < firstRow + rowSpanCount; ++row)
    {
        for(int col = firstColumn; col < firstColumn + columnSpanCount; ++col)
        {
            _cellSpanList.append(CellSpan(row, col, rowSpanCount, columnSpanCount, firstRow, firstColumn));
        }
    }
}

const CellSpan& HHeaderModel::getSpan(int row, int column)
{
    for(QList<CellSpan>::const_iterator iter = _cellSpanList.begin(); iter != _cellSpanList.end(); ++iter)
    {
        if((*iter)._curRow == row && (*iter)._curCol == column)
        {
            return *iter;
        }
    }

    return _InvalidCellSpan;
}

QModelIndex HHeaderModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (row < 0 || column < 0 || _modelData.isEmpty())
        return QModelIndex();

    QMap<int, QMap<int, ModelData*> >::Iterator iterRow = _modelData.find(row);
    if (iterRow == _modelData.end())
        return QModelIndex();

    if (iterRow.value().isEmpty())
        return QModelIndex();

    QMap<int, ModelData*>::Iterator iterCol = iterRow.value().find(column);
    if (iterCol == iterRow.value().end())
        return QModelIndex();

    return createIndex(row, column, iterCol.value());
}

QModelIndex HHeaderModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int HHeaderModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _modelData.size();
}

int HHeaderModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _MaxCol + 1;
}

QVariant HHeaderModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (Qt::DisplayRole == role || Qt::EditRole == role)
    {
        QMap<int, QMap<int, ModelData*> >::Iterator iterRow = _modelData.find(row);
        if (iterRow == _modelData.end() || iterRow.value().isEmpty())
            return QString();

        QMap<int, ModelData*>::Iterator iterCol = iterRow.value().find(col);
        if (iterCol == iterRow.value().end())
        {
            return QString();
        }

        return iterCol.value()->_text;
    }

    return QVariant();
}

Qt::ItemFlags HHeaderModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled;  
}

bool HHeaderModel::setData ( const QModelIndex & index, const QVariant & value, int role)
{
    return false;
}


HHeaderModel::ModelData* HHeaderModel::modelData(const QModelIndex & index) const
{
    if (!index.isValid())
        return NULL;

    int row = index.row();
    int col = index.column();

    QMap<int, QMap<int, ModelData*> >::Iterator iterRow = _modelData.find(row);
    if (iterRow == _modelData.end() || iterRow.value().isEmpty())
        return NULL;

    QMap<int, ModelData*>::Iterator iterCol = iterRow.value().find(col);
    if (iterCol == iterRow.value().end())
    {
        return NULL;
    }

    return iterCol.value();
}

QVariant HHeaderModel::headerData(int section, Qt::Orientation orientation, int role) const
{//重载了sectionSizeFromContents函数，但没有调用默认的处理，所以不会走到这里。
    if (role == Qt::SizeHintRole)
    {
        return QSize(200, 100);
    }

	return QVariant();

   // return QAbstractItemModel::headerData(section,orientation,role);
}